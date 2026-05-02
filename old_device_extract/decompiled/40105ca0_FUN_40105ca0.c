// Function : FUN_40105ca0
// Address  : 0x40105ca0
// Size     : 32 bytes


bool FUN_40105ca0(int param_1)

{
  return (param_1 - 0x2000U & 0xffffdfff) == 0 || param_1 == 0x20;
}

