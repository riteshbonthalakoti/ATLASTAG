---
name: atlas-checkpoint-review
description: >-
  Assess AtlasTag project readiness against Hack Club Half Life weekly milestones and submission criteria.
  Audits schematic, PCB layout, BOM budget compliance, devlog entries, and manufacturing files.
  Use when preparing milestone submissions or weekly project checkpoints.
---

# AtlasTag Milestone & Checkpoint Review Procedure

Use this skill to evaluate project readiness against official Hack Club Half Life milestones (e.g., Week 1: Design Your PCB).

---

## Operating Guidelines

- **Evidence-Based Evaluation:** Rate deliverables solely on actual files present in the repository, not intentions or roadmap items.
- **Do Not Invent Criteria:** Base milestone requirements on official Hack Club Half Life guidelines.
- **Strict Ratings:** Use exactly four statuses: `COMPLETE`, `INCOMPLETE`, `BLOCKED`, or `NOT VERIFIED`.

---

## Step-by-Step Procedure

### 1. Identify Target Milestone
- Identify current Hack Club Half Life milestone:
  - **Week 1:** PCB Design (Schematic capture, PCB layout, BOM within Tier 3 $100 limit, ERC/DRC verification).
  - **Subsequent Weeks:** Fabrication review, component assembly, firmware bring-up, field testing.

### 2. Audit Project Deliverables Checklist
Evaluate each required deliverable:
1. **Schematic Capture:**
   - Are `.kicad_sch` files present in `hardware/kicad/`?
   - Does schematic have 0 ERC errors?
   - Is a vector PDF export available?
2. **PCB Layout:**
   - Is `.kicad_pcb` present in `hardware/kicad/`?
   - Does layout have 0 DRC violations?
   - Are 3D models and clearance envelopes verified?
3. **Bill of Materials (BOM):**
   - Is `bom/BOM.md` populated with verified MPNs, footprints, and distributor prices?
   - Does the total fall within the $100.00 funding limit?
   - Are Indian sourcing logistics accounted for?
4. **Devlog & Time Tracking:**
   - Does `JOURNAL.md` reflect verified engineering sessions?
   - Are project learnings and progress documented?
5. **Git & Branch Hygiene:**
   - Are all changes committed cleanly to `dev`?
   - Is a reviewable PR open or ready for merge to `main`?

### 3. Rate Deliverable Status
For each checkpoint item, assign one rating:
- **`COMPLETE`**: Artifact exists, passes validation, and meets milestone requirements.
- **`INCOMPLETE`**: Artifact exists partially or is in progress.
- **`BLOCKED`**: Missing prerequisite decision, software tool, or hardware dependency.
- **`NOT VERIFIED`**: Artifact exists but automated/manual checks have not been executed.

### 4. Identify Gaps & Risks
- Highlight missing evidence (e.g., ungenerated Gerbers, missing component datasheets, unrouted nets).
- Identify technical risks that could cause submission rejection or fabrication failure.

### 5. Recommend Next Actions
- Define the minimum set of high-priority actions needed to achieve full `COMPLETE` readiness for submission.
