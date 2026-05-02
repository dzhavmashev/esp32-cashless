// Function : FUN_401866a8
// Address  : 0x401866a8
// Size     : 34 bytes


bool FUN_401866a8(byte *param_1)

{
  return (*param_1 & 0xf7) == 0x10 || *param_1 == 0x20;
}

