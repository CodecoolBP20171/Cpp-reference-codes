
#pragma once

struct Node {
  // managed by lists.
  Node *prev = nullptr, *next = nullptr;
  unsigned id = 0;
};
