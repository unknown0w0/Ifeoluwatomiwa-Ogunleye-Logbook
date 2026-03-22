#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>



template <typename VertexVal, typename EdgeVal>
class Graph {
private:
    struct Edge {
        int     to;
        EdgeVal value;
        Edge(int t, const EdgeVal& v) : to(t), value(v) {}
    };

    struct Vertex {
        VertexVal        value;
        std::vector<Edge> edges;
        bool             active;  // false = removed
        Vertex(const VertexVal& v) : value(v), active(true) {}
    };

    std::vector<Vertex> vertices;

    int findVertex(const VertexVal& x) const {
        for (int i = 0; i < (int)vertices.size(); i++)
            if (vertices[i].active && vertices[i].value == x)
                return i;
        return -1;
    }

    int requireVertex(const VertexVal& x) const {
        int idx = findVertex(x);
        if (idx == -1) throw std::runtime_error("Vertex not found");
        return idx;
    }

public:
    Graph() {}

    // adjacent
    bool adjacent(const VertexVal& x, const VertexVal& y) const {
        int from = requireVertex(x);
        int to   = requireVertex(y);
        for (const Edge& e : vertices[from].edges)
            if (e.to == to) return true;
        return false;
    }

    // neighbors
    std::vector<VertexVal> neighbors(const VertexVal& x) const {
        int from = requireVertex(x);
        std::vector<VertexVal> result;
        for (const Edge& e : vertices[from].edges)
            result.push_back(vertices[e.to].value);
        return result;
    }

    void addVertex(const VertexVal& x) {
        if (findVertex(x) != -1) return;  // already exists
        vertices.push_back(Vertex(x));
    }

    void removeVertex(const VertexVal& x) {
        int idx = findVertex(x);
        if (idx == -1) return;
        vertices[idx].active = false;
        vertices[idx].edges.clear();
        for (auto& v : vertices) {
            if (!v.active) continue;
            v.edges.erase(
                std::remove_if(v.edges.begin(), v.edges.end(),
                    [idx](const Edge& e){ return e.to == idx; }),
                v.edges.end()
            );
        }
    }

    void addEdge(const VertexVal& x, const VertexVal& y, const EdgeVal& val = EdgeVal()) {
        int from = requireVertex(x);
        int to   = requireVertex(y);
        if (!adjacent(x, y))
            vertices[from].edges.push_back(Edge(to, val));
    }

    void removeEdge(const VertexVal& x, const VertexVal& y) {
        int from = requireVertex(x);
        int to   = requireVertex(y);
        auto& edges = vertices[from].edges;
        edges.erase(
            std::remove_if(edges.begin(), edges.end(),
                [to](const Edge& e){ return e.to == to; }),
            edges.end()
        );
    }

    VertexVal getVertexValue(const VertexVal& x) const {
        return vertices[requireVertex(x)].value;
    }

    void setVertexValue(const VertexVal& x, const VertexVal& v) {
        int idx = requireVertex(x);
        vertices[idx].value = v;
    }

    EdgeVal getEdgeValue(const VertexVal& x, const VertexVal& y) const {
        int from = requireVertex(x);
        int to   = requireVertex(y);
        for (const Edge& e : vertices[from].edges)
            if (e.to == to) return e.value;
        throw std::runtime_error("Edge not found");
    }

    void setEdgeValue(const VertexVal& x, const VertexVal& y, const EdgeVal& v) {
        int from = requireVertex(x);
        int to   = requireVertex(y);
        for (Edge& e : vertices[from].edges)
            if (e.to == to) { e.value = v; return; }
        throw std::runtime_error("Edge not found");
    }

    std::vector<VertexVal> DepthFirst(const VertexVal& start) const {
        int startIdx = requireVertex(start);
        std::vector<bool> visited(vertices.size(), false);
        std::vector<VertexVal> result;
        std::stack<int> stk;

        stk.push(startIdx);
        while (!stk.empty()) {
            int curr = stk.top(); stk.pop();
            if (visited[curr] || !vertices[curr].active) continue;
            visited[curr] = true;
            result.push_back(vertices[curr].value);
            // Push neighbours in reverse so we visit left-to-right
            for (int i = (int)vertices[curr].edges.size() - 1; i >= 0; i--)
                stk.push(vertices[curr].edges[i].to);
        }
        return result;
    }

    // BreadthFirst
    std::vector<VertexVal> BreadthFirst(const VertexVal& start) const {
        int startIdx = requireVertex(start);
        std::vector<bool> visited(vertices.size(), false);
        std::vector<VertexVal> result;
        std::queue<int> q;

        visited[startIdx] = true;
        q.push(startIdx);
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            if (!vertices[curr].active) continue;
            result.push_back(vertices[curr].value);
            for (const Edge& e : vertices[curr].edges) {
                if (!visited[e.to] && vertices[e.to].active) {
                    visited[e.to] = true;
                    q.push(e.to);
                }
            }
        }
        return result;
    }

    void output() const {
        for (const Vertex& v : vertices) {
            if (!v.active) continue;
            std::cout << v.value << " -> ";
            for (const Edge& e : v.edges)
                std::cout << vertices[e.to].value << "(" << e.value << ") ";
            std::cout << "\n";
        }
    }
};
