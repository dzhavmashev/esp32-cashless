// Function : FUN_40187fa0
// Address  : 0x40187fa0
// Size     : 110 bytes


void FUN_40187fa0(int param_1,char param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x2c) + 4);
  FUN_40188374(param_1,1);
  FUN_401630a4(param_1);
  FUN_40165f28();
  uVar1 = uVar1 >> 4 & 0xf;
  if ((**(uint **)(param_1 + 0x2c) & 0x400008) == 8) {
    FUN_401894c8(*(undefined4 *)(param_1 + 0x24));
  }
  (*(code *)&SUB_40087bcc)(0x10,0);
  if (param_2 != '\0') {
    if ((&DAT_3ffc7b2e)[uVar1 * 0x24] != '\0') {
      memw();
      FUN_40147fe4(6,0x800,1,"ndex=%d",&PTR_DAT_3f4243a8,&PTR_LAB_3f4243c8,0x7b1);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    FUN_40188e54(uVar1);
  }
  return;
}

