// Function : FUN_4018d000
// Address  : 0x4018d000
// Size     : 204 bytes


int FUN_4018d000(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                undefined1 param_6)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = param_1;
  if (param_2 != -1) {
    piVar5 = (int *)0x0;
    piVar3 = (int *)0x0;
    for (piVar4 = (int *)param_1[2]; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[2]) {
      if (*piVar4 == param_2) {
        piVar5 = piVar4;
      }
      piVar3 = piVar4;
    }
    if ((piVar3 == (int *)0x0) || (piVar5 == (int *)0x0)) {
      memw();
      piVar5 = (int *)(*(code *)&SUB_40094dd8)(1,0xc);
      if (piVar5 == (int *)0x0) {
        uVar1 = (*(code *)&SUB_40094b80)();
        FUN_4012113c(1,"unknown event",&DAT_3f40ece4,uVar1,"unknown event");
        return 0x101;
      }
      *piVar5 = param_2;
      piVar5[1] = 0;
      memw();
      iVar2 = FUN_4018cf78(piVar5 + 1,param_3,param_4,param_5,param_6);
      if (iVar2 == 0) {
        if (piVar3 == (int *)0x0) {
          iVar2 = param_1[2];
          param_1[2] = (int)piVar5;
          piVar5[2] = iVar2;
          memw();
          return 0;
        }
        piVar5[2] = piVar3[2];
        piVar3[2] = (int)piVar5;
        memw();
        return 0;
      }
      (*(code *)&SUB_40094d80)(piVar5);
      return iVar2;
    }
  }
  iVar2 = FUN_4018cf78(piVar5 + 1,param_3);
  return iVar2;
}

