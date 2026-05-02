// Function : FUN_400ebbfc
// Address  : 0x400ebbfc
// Size     : 41 bytes


bool FUN_400ebbfc(short *param_1)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = true;
  if (*param_1 != 0) {
    iVar1 = FUN_401844a8(param_1);
    bVar2 = iVar1 == 0x70 || iVar1 == 0x40;
  }
  return bVar2;
}

