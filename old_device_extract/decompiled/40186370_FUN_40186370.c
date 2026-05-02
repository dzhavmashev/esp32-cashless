// Function : FUN_40186370
// Address  : 0x40186370
// Size     : 31 bytes


uint FUN_40186370(uint param_1,uint param_2)

{
  return ((param_1 ^ 0xffffffff) & param_2 | (param_1 ^ param_2 ^ 0xffffffff) & param_1 - param_2)
         >> 0x1f;
}

