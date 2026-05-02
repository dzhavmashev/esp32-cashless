// Function : FUN_401845c5
// Address  : 0x401845c5
// Size     : 30 bytes


void FUN_401845c5(undefined4 param_1,int param_2)

{
  uint unaff_a8;
  int unaff_a9;
  byte bVar1;
  uint unaff_a11;
  byte in_a13;
  
  bVar1 = (byte)unaff_a8 & 0x7f;
  if (unaff_a11 < unaff_a8) {
    bVar1 = bVar1 | in_a13;
  }
  *(byte *)(param_2 + unaff_a9) = bVar1;
  if (unaff_a8 <= unaff_a11) {
    return;
  }
  FUN_401845c5(unaff_a9 + 1U & 0xff);
  return;
}

