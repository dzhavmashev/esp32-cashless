// Function : FUN_4010e220
// Address  : 0x4010e220
// Size     : 74 bytes


undefined4 FUN_4010e220(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    (*(code *)&SUB_40094c54)("id cseg",0x25e,"== NULL","lid pcb");
  }
  uVar1 = 0;
  if ((DAT_3ffc633c & 0x10) != 0) {
    if (((*(ushort *)(param_1 + 0x46) & 0x10) == 0) && (*(code **)(param_1 + 0xbc) != (code *)0x0))
    {
      (**(code **)(param_1 + 0xbc))(*(undefined4 *)(param_1 + 0x38),0xfffffff1);
    }
    FUN_4010d33c(&DAT_3ffc840c,param_1);
    FUN_4010ca80(param_1);
    uVar1 = 1;
  }
  return uVar1;
}

