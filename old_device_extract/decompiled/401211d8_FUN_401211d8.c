// Function : FUN_401211d8
// Address  : 0x401211d8
// Size     : 64 bytes


undefined8 FUN_401211d8(void)

{
  int iVar1;
  uint uVar2;
  int iStack_28;
  int iStack_24;
  
  iVar1 = FUN_40177b4c(&iStack_28,0);
  if (iVar1 == 0) {
    uVar2 = iStack_28 * 1000000 + iStack_24;
    iVar1 = (uint)(uVar2 < (uint)(iStack_28 * 1000000)) +
            (int)((ulonglong)((longlong)iStack_28 * 1000000) >> 0x20) + (iStack_24 >> 0x1f);
  }
  else {
    uVar2 = (*(code *)&SUB_40094b80)();
    iVar1 = (int)((ulonglong)uVar2 * 1000 >> 0x20);
    uVar2 = uVar2 * 1000;
  }
  return CONCAT44(iVar1,uVar2);
}

