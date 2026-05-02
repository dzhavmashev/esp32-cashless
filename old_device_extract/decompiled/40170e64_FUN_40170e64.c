// Function : FUN_40170e64
// Address  : 0x40170e64
// Size     : 116 bytes


int FUN_40170e64(undefined4 *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  code *apcStack_50 [8];
  int iStack_30;
  undefined4 uStack_2c;
  
  pcVar3 = (code *)param_1[3];
  uVar4 = param_1[4];
  iVar2 = 1;
  while( true ) {
    iStack_30 = FUN_40170bfc(param_2,apcStack_50);
    if ((iStack_30 != 0) && (iStack_30 != 5)) {
      return 2;
    }
    uVar5 = 0x1a;
    if (iStack_30 != 5) {
      uVar5 = 10;
    }
    uStack_2c = 10;
    iVar1 = (*pcVar3)(1,uVar5,*param_1,param_1[1],param_1,param_2,uVar4);
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = iStack_30;
    if (iStack_30 == 5) break;
    if (apcStack_50[0] != (code *)0x0) {
      iVar1 = (*apcStack_50[0])(1,uStack_2c,*param_1,param_1[1],param_1,param_2);
      if (iVar1 == 7) break;
      if (iVar1 != 8) {
        return 2;
      }
    }
    FUN_40170ddc(param_2,apcStack_50);
    iVar2 = iVar2 + 1;
  }
  *param_3 = iVar2;
  return iVar1;
}

