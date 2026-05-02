// Function : FUN_401841b8
// Address  : 0x401841b8
// Size     : 17 bytes


int FUN_401841b8(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((*(byte *)(param_1 + 0x20) & 0x20) != 0) {
    iVar1 = param_1 + 0x18;
  }
  return iVar1;
}

