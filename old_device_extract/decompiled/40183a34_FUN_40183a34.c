// Function : FUN_40183a34
// Address  : 0x40183a34
// Size     : 43 bytes


bool FUN_40183a34(uint param_1)

{
  return (param_1 - 0x2b & 0xfd) == 0 || ((param_1 & 0xffffffdf) == 0x45 || param_1 == 0x2e);
}

