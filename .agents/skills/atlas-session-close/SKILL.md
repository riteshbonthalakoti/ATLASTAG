---
name: atlas-session-close
description: >-
  Close an engineering work session for AtlasTag, auditing working-tree status, summarizing verified progress,
  logging honest devlog notes, proposing commit messages, and setting up the next engineering task.
  Use at the end of work sessions or before committing major milestones.
---

# AtlasTag Engineering Session Close Procedure

Use this skill at the end of an engineering work session to ensure clean git status, prepare accurate devlog notes, and plan the next concrete task.

---

## Operating Guidelines

- **Never Fabricate Time:** Never invent or guess tracked hours. Ask the user for their actual session duration if not externally recorded.
- **Never Modify Half Life Blocks:** Do not edit the automated Half Life sync sections in `JOURNAL.md`.
- **Approval Before Action:** Do not commit or push changes without explicit user approval.

---

## Step-by-Step Procedure

### 1. Audit Git Working Tree
- Run `git status` and `git diff --stat`.
- Identify all modified, added, deleted, and untracked files.
- Verify no secrets, temporary test artifacts, or unintended files are present.

### 2. Summarize Verified Work & Evidence
- List concrete tasks accomplished during the session:
  - Documents updated.
  - Components researched or decisions made.
  - Schematics or layouts created or verified.
- Cite evidence produced (e.g., commit SHAs, datasheet citations, ERC/DRC output files).

### 3. Record Open Blockers & Incomplete Tasks
- List items that could not be finished or were deferred.
- Highlight external blockers (missing datasheets, unresolved silicon choices, EDA issues).

### 4. Prepare Factual Devlog Notes
- Ask the user for their exact session duration (in hours or minutes).
- Prepare draft devlog bullet points focusing on:
  - What was built or verified.
  - Key technical learnings or challenges encountered.
  - Concrete next steps.
- Present these draft notes to the user so they can review and rewrite them in their own authentic voice for Half Life.

### 5. Propose Commit Message
- Formulate a clean Conventional Commit message (`feat:`, `fix:`, `docs:`, `chore:`).
- Example:
  ```text
  docs(architecture): close cellular platform trade study and update decision log
  ```
- **Do not commit or push.** Present the proposed message for user approval.

### 6. Define Next Session's Starting Task
- Identify the single, most important next engineering task to begin when work resumes.
- List the exact files and references required for that task.
