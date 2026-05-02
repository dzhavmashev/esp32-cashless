// Function : FUN_40115680
// Address  : 0x40115680
// Size     : 94 bytes


void FUN_40115680(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(&DAT_3ffc6388 + param_1 * 0x18);
  if (piVar1 != (int *)0x0) {
    do {
      piVar2 = (int *)*piVar1;
      if (piVar1[1] == 0) {
        (*(code *)&SUB_40094c54)("!= NULL",0xaa,"d_entry","sg");
      }
      FUN_4010bb10();
      FUN_4010b078(10,piVar1);
      piVar1 = piVar2;
    } while (piVar2 != (int *)0x0);
    *(undefined4 *)(&DAT_3ffc6388 + param_1 * 0x18) = 0;
  }
  (&DAT_3ffc639c)[param_1 * 0x18] = 0;
  memw();
  memw();
  return;
}

