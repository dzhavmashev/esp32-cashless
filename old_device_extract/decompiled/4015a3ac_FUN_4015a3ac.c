// Function : FUN_4015a3ac
// Address  : 0x4015a3ac
// Size     : 86 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015a3ac(uint param_1)

{
  param_1 = param_1 & 0xff;
  if ((*(int *)(_DAT_3ffc8800 + 0x98) != 0) &&
     ((*(char *)(_DAT_3ffc8800 + 0x154) == '\x05' ||
      (((byte)(*(char *)(_DAT_3ffc8800 + 0x154) - 1U) < 2 && ((param_1 == 0xf || (param_1 == 1))))))
     )) {
    FUN_4015a2fc(0xc0,param_1);
    FUN_40157594(&DAT_3ffc87f0,0,param_1 << 8 | 0xc0);
  }
  return;
}

