// Function : FUN_4018bd48
// Address  : 0x4018bd48
// Size     : 64 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018bd48(int param_1)

{
  if (((*(char *)(param_1 + 0xd) != '\0') && (*(char *)(param_1 + 0x168) != '\0')) &&
     (*(short *)(param_1 + 0x184) < *(short *)(param_1 + 0x186))) {
    (**(code **)(_DAT_3ffc1a34 + 0xf8))
              (param_1 + 0x16c,
               ((uint)*(byte *)(param_1 + 0x180) + (uint)*(byte *)(param_1 + 0x181)) * 0x400,0);
    FUN_4018bcbc(param_1);
  }
  return;
}

