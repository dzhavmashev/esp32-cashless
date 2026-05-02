// Function : FUN_400ee394
// Address  : 0x400ee394
// Size     : 235 bytes


int FUN_400ee394(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iStack_24;
  
  iStack_24 = 0x5b4;
  if (param_3 - 1U < 0x5b3) {
    iStack_24 = param_3;
  }
  iVar1 = func_0x40094d68(iStack_24);
  iVar2 = 0;
  iVar6 = param_3;
  if (iVar1 == 0) {
    iVar2 = -8;
  }
  else {
    while ((iVar3 = (*(code *)&LAB_40184637_1)(param_1), iVar3 != 0 &&
           ((iVar3 = (iVar6 >> 0x1f) - iVar6, iVar6 == -1 || (iVar3 < 0))))) {
      iVar4 = (**(code **)(**(int **)(param_1 + 8) + 0x18))();
      if (iVar4 == 0) {
        uVar7 = 1;
      }
      else {
        if ((iVar6 < iVar4) && (iVar3 < 0)) {
          iVar4 = iVar6;
        }
        iVar3 = (**(code **)(**(int **)(param_1 + 8) + 0x28))
                          (*(int **)(param_1 + 8),iVar1,
                           (uint)(iStack_24 < iVar4) * iStack_24 +
                           (uint)(iStack_24 >= iVar4) * iVar4);
        iVar4 = (**(code **)(*param_2 + 0xc))(param_2,iVar1,iVar3);
        iVar2 = iVar2 + iVar4;
        if (iVar3 != iVar4) {
          if (param_2[1] != 0) {
            param_2[1] = 0;
          }
          FUN_400f1ab4(1);
          iVar5 = (**(code **)(*param_2 + 0xc))(param_2,iVar1 + iVar4,iVar3 - iVar4);
          iVar2 = iVar2 + iVar5;
          if (iVar3 - iVar4 != iVar5) goto LAB_400ee457;
        }
        if (param_2[1] != 0) {
LAB_400ee457:
          func_0x40094d88(iVar1);
          return -10;
        }
        if (0 < iVar6) {
          iVar6 = iVar6 - iVar3;
        }
        uVar7 = 0;
      }
      FUN_400f1ab4(uVar7);
    }
    func_0x40094d88(iVar1);
    if (((param_3 >> 0x1f) - param_3 < 0) && (iVar2 != param_3)) {
      iVar2 = -10;
    }
  }
  return iVar2;
}

