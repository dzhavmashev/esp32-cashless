// Function : FUN_4014eb04
// Address  : 0x4014eb04
// Size     : 38 bytes


undefined4 FUN_4014eb04(byte param_1,int param_2)

{
  undefined1 *puVar1;
  
  if ((param_1 < 2) && (param_2 != 0)) {
    puVar1 = &DAT_3ffc89f8;
    if (param_1 == 0) {
      puVar1 = &DAT_3ffc89fe;
    }
    (*(code *)&SUB_4008b3d0)(param_2,puVar1,6);
    return 1;
  }
  return 0;
}

