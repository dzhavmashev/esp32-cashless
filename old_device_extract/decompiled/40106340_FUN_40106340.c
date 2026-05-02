// Function : FUN_40106340
// Address  : 0x40106340
// Size     : 37 bytes


bool FUN_40106340(int param_1)

{
  bool bVar1;
  
  bVar1 = true;
  if (param_1 != 8) {
    bVar1 = (param_1 - 0x800U & 0xfffff7ff) == 0 || param_1 == 2;
  }
  return bVar1;
}

