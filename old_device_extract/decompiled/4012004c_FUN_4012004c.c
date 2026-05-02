// Function : FUN_4012004c
// Address  : 0x4012004c
// Size     : 162 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4012004c(undefined1 *param_1,undefined1 *param_2,undefined4 param_3)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 in_t0;
  
  if (_DAT_3ffc6d20 != 0) {
    pcVar2 = *(code **)(_DAT_3ffc6d20 + 0x24);
    uVar3 = *(undefined4 *)(_DAT_3ffc6d20 + 0x28);
    pcVar4 = *(code **)(_DAT_3ffc6d20 + 0x1c);
    uVar5 = *(undefined4 *)(_DAT_3ffc6d20 + 0x20);
    memw();
    iVar1 = (*(code *)&SUB_4008fab8)(_DAT_3ffc6d24,0,0);
    if (iVar1 == 1) goto LAB_4012008d;
    uVar6 = 0xaa;
    pcVar7 = "release";
    uVar5 = in_t0;
    while( true ) {
      (*(code *)&SUB_40094c54)("ing/src/manager.c",uVar6,"_deinit",pcVar7);
      in_t0 = uVar5;
LAB_4012008d:
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)(uVar5,param_1,param_2);
      }
      uVar5 = in_t0;
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)(uVar3,param_1,param_2);
      }
      iVar1 = FUN_4018cf2c(_DAT_3ffbf670,param_1,param_2,param_3,0xffffffff);
      if (iVar1 != 0) {
        uVar6 = (*(code *)&SUB_40094b80)();
        FUN_4012113c(1,"nager.c","rov_mgr",uVar6,"nager.c",param_1);
      }
      iVar1 = (*(code *)&SUB_40090010)(_DAT_3ffc6d24,0xffffffff);
      param_1 = &DAT_3ffc6d24;
      param_2 = &DAT_3ffbf670;
      if (iVar1 == 1) break;
      uVar6 = 0xbc;
      pcVar7 = "t loop\n";
    }
  }
  return;
}

