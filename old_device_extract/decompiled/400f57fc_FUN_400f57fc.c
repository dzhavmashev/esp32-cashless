// Function : FUN_400f57fc
// Address  : 0x400f57fc
// Size     : 154 bytes


undefined4 FUN_400f57fc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  int *piVar4;
  int *in_t0;
  
  iVar1 = FUN_400f57dc(param_1);
  if (iVar1 == 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"_enable","e",uVar2,"_enable","llup_en",0x28);
    uVar2 = 0x102;
  }
  else {
    (*(code *)&SUB_40092a98)(0x3ffbdc68,0xffffffff);
    piVar4 = (int *)(&DAT_3f414010 + *(int *)(&DAT_3f414400 + param_1 * 4) * 0x38);
    puVar3 = (uint *)*piVar4;
    if (puVar3 + -0xffc0000 < (uint *)0x13ffd) {
      piVar4 = in_t0;
      (*(code *)&SUB_40094c54)("ude/hal/rtc_io_ll.h",0x3a,"_deinit","io_ll.h");
    }
    memw();
    memw();
    *puVar3 = (piVar4[1] ^ 0xffffffffU) & *puVar3;
    memw();
    (*(code *)&SUB_40092bec)(0x3ffbdc68);
    uVar2 = 0;
  }
  return uVar2;
}

