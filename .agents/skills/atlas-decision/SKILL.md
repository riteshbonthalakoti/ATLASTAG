---
name: atlas-decision
description: >-
  Produce structured, evidence-based engineering trade-offs and decision log entries for AtlasTag.
  Use when comparing hardware candidates, resolving architectural options, or updating DECISION_LOG.md.
---

# AtlasTag Engineering Decision & Trade-Off Procedure

Use this skill to systematically evaluate competing hardware options and record formal decisions in `docs/decisions/DECISION_LOG.md`.

---

## Operating Guidelines

- **Never Prematurely Close Decisions:** Never close a decision simply because a part is tentatively listed in the preliminary BOM. Preserve `OPEN` status until formal evidence justifies closing it.
- **Traceable Justifications:** Every decision must cite concrete evidence (datasheets, cost tables, manufacturability limits, power measurements).
- **User Approval Required:** Always present the proposed trade-off analysis and decision entry to the user for explicit approval before changing a decision status to `CLOSED`.

---

## Step-by-Step Procedure

### 1. Frame the Decision
- State the exact decision topic (e.g., Cellular/GNSS Platform, Accelerometer, Storage, Antenna Topology, Power Architecture).
- Define non-negotiable constraints:
  - Budget ceiling ($100 parts funding).
  - Maximum PCB envelope (e.g., 40×30mm vs. 50×40mm).
  - Sleep current target (< 10 µA).
  - Assembly capabilities (hand soldering vs. stencil reflow / hot air).

### 2. Identify Viable Candidates
- List all candidates with exact Manufacturer Part Numbers (MPNs) from `docs/research/RESEARCH_INDEX.md`.
- Eliminate options that violate hard constraints with explicit reasons.

### 3. Build Comparison Matrix
Compare candidates across standard criteria:
1. **Electrical & Power:** Active current, sleep floor, voltage compatibility.
2. **Physical & Assembly:** Footprint size, pin pitch, ease of inspection (LCC castellations vs. LGA/BGA).
3. **RF & Antenna Integration:** External matching components, ground plane requirements.
4. **Firmware & Toolchain:** SDK maturity (Zephyr, FreeRTOS, AT commands), debugger requirements.
5. **Cost & Sourcing:** Unit price in USD and INR, stock availability at authorized distributors.
6. **Project Risks:** Solder bridging risk, single-source vendor lock-in, errata.

### 4. Formulate Recommendation
- Identify the technically superior candidate based on the matrix.
- Document remaining uncertainties and failure modes (e.g., "Requires 4-layer controlled impedance board", "LGA pads cannot be visually inspected without X-ray/microscope").

### 5. Propose Decision Log Entry
Draft an update to `docs/decisions/DECISION_LOG.md` using the project's standard schema:

```markdown
| Date | Topic | Options Considered | Decision | Justification | Status |
| :--- | :--- | :--- | :--- | :--- | :--- |
| YYYY-MM-DD | [Topic Name] | [List of MPNs] | [Selected MPN or PENDING] | [Evidence-based justification citing power, cost, assembly] | OPEN / CLOSED |
```

### 6. Review & User Sign-Off
- Present the draft entry to the user.
- Upon approval, update `docs/decisions/DECISION_LOG.md`.
