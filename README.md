# leetcode_practice

This repo sync the issue that title with "leetcode" from https://github.com/tar-ooo-ooo/skill-ai.

Then saving code and solutions by myself to this repo.


## Stucture

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

## labels

- `source:leetcode`
- `status:todo`
- `status:solving`
- `status:solved`
- `difficulty:easy`
- `difficulty:medium`
- `difficulty:hard`
- `topic:array`
- `topic:string`
- `topic:hash-table`
- `topic:two-pointers`
- `topic:binary-search`
- `topic:tree`
- `topic:graph`
- `topic:dp`
- `topic:backtracking`

## Workflow 1: 每天同步 issue

檔案： [.github/workflows/sync-leetcode-issues.yml](/D:/project/leetcode_practice/.github/workflows/sync-leetcode-issues.yml)

用途：

- 每天排程抓來源 repo issues
- 篩出 title 含 `leetcode` 的 issue
- 如果本 repo 還沒有同步過，就建立新 issue

同步建立的 issue 會自動帶：

- `source:leetcode`
- `status:todo`

同步 issue body 內會放 hidden marker，後續 workflow 用它找到對應 issue。

## Workflow 2: 手動更新解題 issue

檔案： [.github/workflows/update-leetcode-issue.yml](/D:/project/leetcode_practice/.github/workflows/update-leetcode-issue.yml)

用途：

- 手動輸入來源 issue 編號
- 指定 slug / difficulty / topics / solution path / notes path
- 自動到對應 issue 留言
- 更新 labels
- 可選擇是否關閉 issue
