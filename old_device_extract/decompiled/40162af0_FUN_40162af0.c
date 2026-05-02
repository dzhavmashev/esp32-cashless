// Function : FUN_40162af0
// Address  : 0x40162af0
// Size     : 77 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40162af0(int param_1)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(param_1 + 4);
  puVar1[1] = *(uint *)(param_1 + 0x10);
  if (*(char *)(param_1 + 0x1a) == '\x06') {
    memw();
    if ((*puVar1 & 0xfff) != *(uint *)(_DAT_3ffc0034 + 0x3b8)) {
      memw();
      FUN_40147fe4(6,0x800,1,"lure cb","s_func_app.c",0x3fc);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    FUN_4018c68c(puVar1,*(undefined4 *)(param_1 + 8),*(undefined2 *)(param_1 + 0xc));
  }
  FUN_4018a7b8(param_1);
  return;
}

