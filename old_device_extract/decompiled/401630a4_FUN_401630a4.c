// Function : FUN_401630a4
// Address  : 0x401630a4
// Size     : 82 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401630a4(int param_1)

{
  if (param_1 == 0) {
    FUN_40147fe4(6,0x800,1,"e queue","s_func_app.c",0xb26);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((**(uint **)(param_1 + 0x2c) & 0x4000000) != 0) {
    *(char *)(_DAT_3ffc0034 + 0x1f) = *(char *)(_DAT_3ffc0034 + 0x1f) + -1;
    memw();
    memw();
    return;
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  **(int **)(_DAT_3ffc0034 + 0x348) = param_1;
  *(int *)(_DAT_3ffc0034 + 0x348) = param_1 + 0x28;
  memw();
  return;
}

