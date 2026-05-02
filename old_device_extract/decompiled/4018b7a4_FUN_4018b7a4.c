// Function : FUN_4018b7a4
// Address  : 0x4018b7a4
// Size     : 41 bytes


int FUN_4018b7a4(byte *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x1e;
  if ((param_1[1] & 3) != 3) {
    iVar2 = 0x18;
  }
  iVar1 = iVar2 + 2;
  if ((*param_1 & 0x8c) != 0x88) {
    iVar1 = iVar2;
  }
  return iVar1;
}

