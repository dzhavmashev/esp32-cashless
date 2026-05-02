// Function : FUN_400fbff8
// Address  : 0x400fbff8
// Size     : 197 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fbff8(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iStack_48;
  undefined1 auStack_44 [2];
  byte bStack_42;
  uint uStack_24;
  
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  iVar1 = 0x1102;
  if (*(int *)(param_1 + 0x3c) == -1) goto LAB_400fc049;
  if ((*(int *)(param_2 + 0xc) == -1) && (iVar1 = FUN_400fb0f4(param_2), iVar1 != 0))
  goto LAB_400fc049;
  param_5 = 0x7d;
  uVar3 = *(uint *)(param_1 + 0x3c);
LAB_400fc01a:
  do {
    uVar2 = uVar3;
    if (param_5 < uVar2) {
      iVar1 = 0;
LAB_400fc049:
      param_1 = iVar1;
      uVar2 = uStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (uStack_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
    }
    else {
      memw();
      iVar1 = (*(code *)&LAB_40184b76_2)(param_1 + 0x18,uVar2,&iStack_48);
      if (iVar1 != 0) goto LAB_400fc049;
      if (iStack_48 == 2) {
        iVar1 = FUN_40184b50(param_1,uVar2,auStack_44);
        if (((iVar1 == 0) &&
            (iVar1 = FUN_400faef8(param_2 + 0x44,auStack_44,*(undefined4 *)(param_2 + 0x38)),
            iVar1 == 0)) && (iVar1 = FUN_400fb184(param_2,auStack_44), iVar1 == 0)) {
          uVar3 = bStack_42 + uVar2;
          if (0x7e < uVar3) goto LAB_400fc03c;
          do {
            uVar2 = uVar2 + 1;
            if (uVar3 <= uVar2) goto LAB_400fc01a;
            FUN_40184b50(param_1,uVar2,auStack_44);
            iVar1 = FUN_400fb184(param_2,auStack_44);
          } while (iVar1 == 0);
        }
        goto LAB_400fc049;
      }
      if (*(uint *)(param_1 + 0x3c) == uVar2) {
LAB_400fc03c:
        iVar1 = -1;
        goto LAB_400fc049;
      }
    }
    uVar3 = uVar2 + 1;
  } while( true );
}

