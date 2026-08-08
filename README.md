# leetcode_practice

This repo is for:

1. Syncing issues from `tar-ooo-ooo/skill-ai` into this repo
2. Saving my LeetCode solutions and notes here
3. Manually updating the synced issue after solving

## Structure

```text
.github/
  ISSUE_TEMPLATE/
    leetcode-practice.md
  workflows/
    sync-leetcode-issues.yml
    update-leetcode-issue.yml
problems/
templates/
  solution-note.md
leetcode.config.json
```

## Labels

- `leetcode`
- `todo`
- `solving`
- `solved`
- `easy`
- `medium`
- `hard`
- `array`
- `string`
- `hash-table`
- `two-pointers`
- `binary-search`
- `tree`
- `graph`
- `dp`
- `backtracking`


## Workflows

[.github/workflows/sync-leetcode-issues.yml](/D:/project/leetcode_practice/.github/workflows/sync-leetcode-issues.yml)

- scheduled daily
- can also be run manually
- creates synced issues with label `todo`

[.github/workflows/update-leetcode-issue.yml](/D:/project/leetcode_practice/.github/workflows/update-leetcode-issue.yml)

- manual only
- comments on the synced issue
- updates difficulty / topic / status labels
- optionally closes the issue
