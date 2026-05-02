// Function : FUN_400fb0f4
// Address  : 0x400fb0f4
// Size     : 144 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fb0f4(int param_1)

{
  int iVar1;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined4 uStack_28;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar1 = -1;
  if (*(int *)(param_1 + 0xc) == -1) {
    *(undefined4 *)(param_1 + 0xc) = 0xfffffffe;
    uStack_3b = 0xff;
    memw();
    local_44 = 0xfffffffe;
    uStack_40 = *(undefined4 *)(param_1 + 0x10);
    uStack_3c = *(undefined1 *)(param_1 + 0x14);
    memw();
    memw();
    uStack_28 = FUN_400fb0e0(&local_44);
    memw();
    iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x14))
                      (*(int **)(param_1 + 0x50),*(undefined4 *)(param_1 + 8),&local_44,0x20);
    if (iVar1 == 0) goto LAB_400fb16c;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  while( true ) {
    param_1 = iVar1;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    memw();
    iVar1 = (*(code *)&SUB_40082ec4)();
LAB_400fb16c:
    *(int *)(param_1 + 0x38) = iVar1;
    *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
    memw();
  }
  return;
}

