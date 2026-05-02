// Function : FUN_40123674
// Address  : 0x40123674
// Size     : 193 bytes


void FUN_40123674(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  
  FUN_4016b200();
  iVar1 = (*(code *)&SUB_40094dd8)(0x770,1);
  if (iVar1 == 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"ate","0x%x)\n\n",uVar2,"ate");
    (*(code *)&SUB_40094bc8)();
  }
  iVar3 = (*(code *)&SUB_400081d4)(0);
  iVar4 = FUN_40123420(iVar1);
  iVar6 = 2;
  if ((iVar4 == 0) && (iVar6 = 1, iVar3 != 5)) {
    iVar6 = 0;
  }
  uVar5 = FUN_4011ecfc(&uStack_26);
  if (uVar5 != 0) {
    (*(code *)&SUB_4008effc)(uVar5,"ta_mac)",0x2e3,"n data\n","cal_mac");
  }
  *(undefined2 *)(iVar1 + 4) = uStack_26;
  memw();
  *(undefined2 *)(iVar1 + 6) = uStack_24;
  memw();
  *(undefined2 *)(iVar1 + 8) = uStack_22;
  memw();
  memw();
  iVar3 = FUN_4016b2d4("rom_nvs",iVar1,iVar6);
  uVar7 = uVar5;
  if (iVar6 != 1) {
    uVar7 = 1;
  }
  if ((uVar7 & 0xff) == 0) {
LAB_4012371d:
    if ((iVar6 == 2) || (iVar3 != 1)) goto LAB_40123729;
  }
  else {
    if (iVar4 != 0) {
      uVar5 = 1;
    }
    if ((uVar5 & 0xff) == 0) goto LAB_4012371d;
  }
  FUN_4012357c(iVar1);
LAB_40123729:
  (*(code *)&SUB_40094d80)(iVar1);
  return;
}

