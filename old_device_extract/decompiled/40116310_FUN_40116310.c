// Function : FUN_40116310
// Address  : 0x40116310
// Size     : 115 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_40116310(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  piVar1 = (int *)FUN_40185484(param_1,param_2);
  if (piVar1 != (int *)0x0) goto LAB_40116361;
  piVar2 = *(int **)(param_1 + 0xcc);
  piVar1 = (int *)FUN_4010b058(0xb);
  if (piVar1 == (int *)0x0) goto LAB_40116361;
  iVar3 = 0;
  if (param_2 != (int *)0x0) {
    iVar3 = *param_2;
  }
  piVar1[2] = 0;
  *(undefined1 *)(piVar1 + 3) = 0;
  memw();
  piVar1[1] = iVar3;
  if (piVar2 == (int *)0x0) {
    if (*param_2 != _DAT_3ffc6480) {
      pcVar5 = "/igmp.c";
      uVar4 = 0x113;
      goto LAB_40116350;
    }
  }
  else {
    if (*param_2 != _DAT_3ffc6480) {
      *piVar1 = *piVar2;
      *piVar2 = (int)piVar1;
      memw();
      goto LAB_40116361;
    }
    pcVar5 = "systems";
    uVar4 = 0x119;
LAB_40116350:
    memw();
    piVar1 = (int *)(*(code *)&SUB_40094c54)("gmp_msg",uVar4,"mp_send",pcVar5);
  }
  *piVar1 = (int)piVar2;
  *(int **)(param_1 + 0xcc) = piVar1;
LAB_40116361:
  memw();
  return piVar1;
}

