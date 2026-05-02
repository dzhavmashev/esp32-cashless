// Function : FUN_4015a200
// Address  : 0x4015a200
// Size     : 59 bytes


bool FUN_4015a200(int param_1,undefined1 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    FUN_40147fe4(1,0x800,1,"",&PTR_DAT_3f4240a4,0xd7);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar1 = FUN_40187c28(param_1);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x135) = param_2;
    memw();
  }
  memw();
  return iVar1 != 0;
}

