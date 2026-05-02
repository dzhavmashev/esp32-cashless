// Function : FUN_4016bc68
// Address  : 0x4016bc68
// Size     : 91 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016bc68(short param_1)

{
  uint uVar1;
  
  (**(code **)(_DAT_3ffc7e64 + 0xc0))();
  (**(code **)(_DAT_3ffc7e64 + 0xd8))(param_1 << 8 | _DAT_3ffc073c,_DAT_3ffc073e);
  uVar1 = (**(code **)(_DAT_3ffc7e64 + 0x10c))(_DAT_3ffc073e);
  (**(code **)(_DAT_3ffc7e64 + 0xdc))((uVar1 & 0xffff) * 8 + 0x3ffca4d4);
  (**(code **)(_DAT_3ffc7e64 + 0x3c))(1);
  (**(code **)(_DAT_3ffc7e64 + 0x11c))();
  return;
}

