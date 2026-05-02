// Function : FUN_400fb554
// Address  : 0x400fb554
// Size     : 339 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fb554(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int extraout_a3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_4c [4];
  int iStack_48;
  undefined1 auStack_44 [2];
  byte bStack_42;
  int iStack_40;
  int iStack_24;
  
  iVar5 = param_1 + 0x18;
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  FUN_400fb430(param_1,auStack_4c);
  iVar1 = (*(code *)&LAB_40184b76_2)(iVar5,param_2,&iStack_48);
  iVar3 = iVar1;
  if (iVar1 != 0) goto LAB_400fb5ea;
  if (iStack_48 == 2) {
    iVar3 = FUN_40184b50(param_1,param_2,auStack_44);
    if (iVar3 != 0) goto LAB_400fb5ea;
    iVar2 = FUN_400fc574(auStack_44);
    iVar3 = param_1 + 0x44;
    iVar6 = param_2;
    if (iStack_40 == iVar2) goto LAB_400fb60b;
    FUN_400faff8(iVar3,param_2);
    iVar3 = FUN_40184a44(param_1,param_2,0);
    *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + -1;
    memw();
    *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
    memw();
  }
  else {
    iVar3 = FUN_40184a44(param_1,param_2,0);
  }
  if (iVar3 != 0) goto LAB_400fb5ea;
  uVar4 = 1;
  do {
    iVar5 = *(int *)(param_1 + 0x3c);
    if (((iVar5 != param_2) || (iVar3 = FUN_400fb50c(param_1,param_2,uVar4), iVar3 == 0)) &&
       (iVar3 = iVar1, *(uint *)(param_1 + 0x38) < uVar4 + param_2)) {
      *(uint *)(param_1 + 0x38) = uVar4 + param_2;
      memw();
    }
LAB_400fb5ea:
    do {
      param_1 = iVar3;
      iVar3 = iStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return;
      }
      memw();
      (*(code *)&SUB_40082ec4)();
      iVar1 = param_1;
      iVar6 = extraout_a3;
LAB_400fb60b:
      FUN_400faff8(iVar3,iVar6);
      uVar4 = (uint)bStack_42;
      iVar6 = param_2 + uVar4;
      while (iVar6 = iVar6 + -1, param_2 <= iVar6) {
        memw();
        iVar3 = (*(code *)&LAB_40184b76_2)(iVar5,iVar6,&iStack_48);
        if (iVar3 != 0) goto LAB_400fb5ea;
        if (iStack_48 == 2) {
          *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + -1;
          memw();
        }
        *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
        memw();
        memw();
      }
      if (uVar4 == 1) {
        iVar3 = FUN_40184a44(param_1,param_2,0);
      }
      else {
        iVar3 = FUN_40184aa4(param_1,param_2,param_2 + uVar4,0);
      }
    } while (iVar3 != 0);
  } while( true );
}

