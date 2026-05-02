// Function : FUN_400f4104
// Address  : 0x400f4104
// Size     : 327 bytes


undefined4 FUN_400f4104(uint *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  
  uVar6 = *param_1;
  uVar5 = param_1[1];
  if ((uVar6 == 0 && uVar5 == 0) || ((uVar6 & 0xf1000000) != 0 || (uVar5 & 0xffffff00) != 0)) {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar8 = " input\n";
  }
  else {
    iVar4 = 0;
    if (((param_1[2] & 2) == 0) ||
       (iVar4 = 0, (uVar6 & 0xf1000000) == 0 && (uVar5 & 0xfffffffc) == 0)) {
      do {
        uVar2 = (*(code *)&SUB_4000c84c)(uVar6,uVar5,iVar4);
        if ((uVar2 & 1) != 0) {
          puVar7 = *(uint **)(&DAT_3f413ee8 + iVar4 * 4);
          if (puVar7 != (uint *)0x0) goto LAB_400f4196;
          uVar1 = 0x14c;
          pcVar10 = "t mode\n";
          pcVar9 = "unc_sel";
          pcVar8 = "/driver/gpio.c";
          while( true ) {
            (*(code *)&SUB_40094c54)(pcVar8,uVar1,pcVar9,pcVar10);
LAB_400f4196:
            iVar3 = FUN_400f36fc(iVar4);
            if (iVar3 != 0) {
              FUN_400f57fc(iVar4);
            }
            if ((param_1[2] & 1) == 0) {
              FUN_400f3734(iVar4);
            }
            else {
              FUN_400f3938();
            }
            if ((param_1[2] & 4) == 0) {
              FUN_400f38d0(iVar4);
            }
            else {
              FUN_400f3868();
            }
            if ((param_1[2] & 2) == 0) {
              FUN_400f379c(iVar4);
            }
            else {
              FUN_400f3a0c();
            }
            if (param_1[3] == 0) {
              FUN_400f3b60(iVar4);
            }
            else {
              FUN_400f3ab8();
            }
            if (param_1[4] == 0) {
              FUN_400f3c98(iVar4);
            }
            else {
              FUN_400f3bec();
            }
            FUN_400f3d28(iVar4,param_1[5]);
            if (param_1[5] == 0) {
              FUN_400f3e44(iVar4);
            }
            else {
              FUN_400f3dcc();
            }
            if ((uint *)0x13ffc < puVar7 + -0xffc0000) break;
            uVar1 = 0x27d;
            pcVar10 = "t->num)";
            pcVar9 = "service";
            pcVar8 = "ude/hal/gpio_ll.h";
          }
          memw();
          memw();
          *puVar7 = *puVar7 & 0xffff8fff | 0x2000;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != 0x28);
      memw();
      return 0;
    }
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar8 = "error \n";
  }
  FUN_4012113c(1,"encyMhz",pcVar8,uVar1,"encyMhz");
  return 0x102;
}

