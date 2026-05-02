// Function : FUN_400f5898
// Address  : 0x400f5898
// Size     : 151 bytes


undefined4 FUN_400f5898(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint uVar4;
  uint in_t0;
  
  iVar1 = FUN_400f57dc(param_1);
  if (iVar1 == 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"_enable","e",uVar2,"_enable","_enable",0x6d);
    uVar2 = 0x102;
  }
  else {
    (*(code *)&SUB_40092a98)(0x3ffbdc68,0xffffffff);
    uVar4 = *(uint *)(&DAT_3f414020 + *(int *)(&DAT_3f414400 + param_1 * 4) * 0x38);
    if (uVar4 != 0) {
      puVar3 = *(uint **)(&DAT_3f414010 + *(int *)(&DAT_3f414400 + param_1 * 4) * 0x38);
      if (puVar3 + -0xffc0000 < (uint *)0x13ffd) {
        uVar4 = in_t0;
        (*(code *)&SUB_40094c54)("ude/hal/rtc_io_ll.h",0xab,"lup_dis"," error\n");
      }
      memw();
      memw();
      *puVar3 = uVar4 | *puVar3;
    }
    memw();
    (*(code *)&SUB_40092bec)(0x3ffbdc68);
    uVar2 = 0;
  }
  return uVar2;
}

