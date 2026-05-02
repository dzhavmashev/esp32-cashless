// Function : FUN_40184780
// Address  : 0x40184780
// Size     : 16 bytes


uint FUN_40184780(int param_1)

{
  uint uVar1;
  
  if ((*(byte *)(param_1 + 0xf) & 0x80) == 0) {
    uVar1 = *(uint *)(param_1 + 8);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0xc) >> 0x18 & 0x7f;
  }
  return uVar1;
}

