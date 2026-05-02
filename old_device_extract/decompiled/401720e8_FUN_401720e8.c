// Function : FUN_401720e8
// Address  : 0x401720e8
// Size     : 35 bytes


undefined4 FUN_401720e8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 auStack_24 [9];
  
  uVar2 = 0;
  if (-1 < *(int *)(param_1 + 0x10)) {
    iVar1 = FUN_40109af0(*(int *)(param_1 + 0x10),0x4004667f,auStack_24);
    uVar2 = auStack_24[0];
    if (iVar1 < 0) {
      *(undefined1 *)(param_1 + 0x14) = 1;
      uVar2 = 0;
    }
  }
  return uVar2;
}

