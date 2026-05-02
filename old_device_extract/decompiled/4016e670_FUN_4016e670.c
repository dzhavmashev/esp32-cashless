// Function : FUN_4016e670
// Address  : 0x4016e670
// Size     : 54 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_4016e670(undefined1 param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (**(code **)(_DAT_3ffc7e64 + 0x98))(100,0,param_1);
  uVar2 = (**(code **)(_DAT_3ffc7e64 + 0x2c))((uVar1 & 0xf) - 5,0xf,1);
  return (uVar1 & 0xfffffff0 | uVar2) & 0xff;
}

