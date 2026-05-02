// Function : FUN_40126194
// Address  : 0x40126194
// Size     : 145 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40126194(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_12c [132];
  undefined1 auStack_a8 [132];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  iVar1 = FUN_40128d98(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x40),param_4,auStack_12c,
                       auStack_12c + *(int *)(*(int *)(param_1 + 0x48) + 0x44));
  if (-1 < iVar1) goto LAB_401261e1;
  do {
    param_1 = -1;
    while( true ) {
      param_3 = iStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
LAB_401261e1:
      iVar1 = FUN_40128d98(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x40),param_6,auStack_a8,
                           auStack_a8 + *(int *)(*(int *)(param_1 + 0x48) + 0x44));
      if (iVar1 < 0) break;
      iVar1 = param_1 + 0x48;
      iVar2 = *(int *)(*(int *)(param_1 + 0x48) + 0x44) << 1;
      memw();
      param_1 = 0;
      FUN_40126034(iVar1,param_2,param_3,auStack_12c,iVar2,param_5,auStack_a8,iVar2,param_7);
    }
  } while( true );
}

