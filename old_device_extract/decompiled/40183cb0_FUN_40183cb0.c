// Function : FUN_40183cb0
// Address  : 0x40183cb0
// Size     : 42 bytes


undefined1 FUN_40183cb0(int param_1)

{
  uint uVar1;
  byte *pbVar2;
  
  if (*(char *)(param_1 + 0x1d) == '\0') {
    pbVar2 = *(byte **)(param_1 + 0x14);
    uVar1 = 0xffffffff;
    if (pbVar2 < *(byte **)(param_1 + 0x18)) {
      *(byte **)(param_1 + 0x14) = pbVar2 + 1;
      uVar1 = (uint)*pbVar2;
    }
    *(char *)(param_1 + 0x1c) = (-1 < (int)uVar1) * (char)uVar1;
    *(undefined1 *)(param_1 + 0x1d) = 1;
  }
  return *(undefined1 *)(param_1 + 0x1c);
}

