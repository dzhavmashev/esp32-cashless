// Function : FUN_40164fac
// Address  : 0x40164fac
// Size     : 52 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40164fac(char param_1,byte param_2)

{
  if (param_1 == '\0') {
    if ((_DAT_3ffc06f0 & 1 << (param_2 & 0x1f)) == 0) {
      return _DAT_3ffc7d58;
    }
  }
  else if ((param_2 == 0) || ((_DAT_3ffc06f0 & 1 << (param_2 & 0x1f)) == 0)) {
    return _DAT_3ffc7d5c;
  }
  return *(undefined4 *)(&DAT_3ffc7d14 + (uint)param_2 * 4);
}

