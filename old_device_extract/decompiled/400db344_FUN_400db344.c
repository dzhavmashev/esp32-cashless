// Function : FUN_400db344
// Address  : 0x400db344
// Size     : 22 bytes


void FUN_400db344(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != param_1[1]) {
    FUN_400db318(iVar1);
    param_1[1] = iVar1;
  }
  return;
}

