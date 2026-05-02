// Function : FUN_400d98d0
// Address  : 0x400d98d0
// Size     : 55 bytes


bool FUN_400d98d0(int param_1,undefined1 param_2)

{
  int iVar1;
  
  FUN_400ec7a4(param_1," in SSL config",0);
  iVar1 = FUN_400eccc8(param_1,"already activated",param_2);
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 0x104) = param_2;
  }
  FUN_400ec888(param_1);
  return iVar1 != 0;
}

