// Function : FUN_40155074
// Address  : 0x40155074
// Size     : 30 bytes


bool FUN_40155074(uint param_1)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = FUN_40155000();
  bVar1 = false;
  if ((param_1 & 0xff) <= uVar2) {
    uVar2 = FUN_40155040();
    bVar1 = uVar2 <= (param_1 & 0xff);
  }
  return bVar1;
}

