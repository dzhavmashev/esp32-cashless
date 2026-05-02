// Function : FUN_40171cfc
// Address  : 0x40171cfc
// Size     : 141 bytes


/* WARNING: Removing unreachable block (ram,0x40171d87) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40171cfc(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    (*(code *)&SUB_40082de4)(0x3ffc0770);
    piVar2 = (int *)&DAT_3ffc7ec4;
    iVar1 = _DAT_3ffc7ec4;
    while (iVar1 != 0) {
      if (param_1 == *(int **)(iVar1 + 0xc)) {
        *piVar2 = *(int *)(iVar1 + 0x14);
        goto LAB_40171d70;
      }
      piVar2 = (int *)(iVar1 + 0x14);
      iVar1 = *(int *)(iVar1 + 0x14);
    }
    puVar3 = (undefined4 *)&DAT_3ffc7ec0;
    for (iVar1 = _DAT_3ffc7ec0; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x14)) {
      if ((*(uint *)(iVar1 + 0x10) & 1) == 0) {
        if (param_1 == *(int **)(iVar1 + 0xc)) {
          *puVar3 = *(undefined4 *)(iVar1 + 0x14);
          break;
        }
      }
      else if (param_1 == (int *)**(int **)(iVar1 + 0xc)) {
        *puVar3 = *(undefined4 *)(iVar1 + 0x14);
        (*(code *)&SUB_40094d80)();
        break;
      }
      puVar3 = (undefined4 *)(iVar1 + 0x14);
    }
LAB_40171d70:
    (*(code *)&SUB_40082e0c)(0x3ffc0770);
    if (iVar1 == 0) {
      (*(code *)&SUB_40094bc8)();
    }
  }
  return;
}

