// Function : FUN_400f5ccc
// Address  : 0x400f5ccc
// Size     : 83 bytes


void FUN_400f5ccc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1 * 0x10;
  (*(code *)&SUB_40092a98)(iVar1 + 0x3ffbdc7c,0xffffffff);
  if (*(char *)(iVar1 + 0x3ffbdc84) == '\0') {
    uVar2 = *(undefined4 *)(&DAT_3f414520 + param_1 * 0x18);
    FUN_400f552c(uVar2);
    if (param_1 != 0) {
      FUN_400f56b0(uVar2);
    }
    *(undefined1 *)(iVar1 + 0x3ffbdc84) = 1;
    memw();
  }
  memw();
  (*(code *)&SUB_40092bec)(iVar1 + 0x3ffbdc7c);
  return;
}

