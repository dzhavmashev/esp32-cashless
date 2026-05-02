// Function : FUN_400f22e0
// Address  : 0x400f22e0
// Size     : 424 bytes


undefined4 FUN_400f22e0(int param_1,char param_2,uint param_3,uint param_4,uint param_5,int param_6)

{
  uint *puVar1;
  int iVar2;
  char cVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  uint *in_t0;
  
  puVar4 = (uint *)(param_3 & 0xff);
  cVar3 = (char)param_3;
  puVar5 = (uint *)(param_4 & 0xff);
  param_5 = param_5 & 0xff;
  if (param_2 < 0) goto LAB_400f236c;
  param_6 = 0x3ffbdbd0;
  puVar1 = (uint *)(param_1 * 0x20);
  puVar6 = puVar1 + 0xffef6f4;
  if ((int)(char)puVar1[0xffef6f7] != (int)param_2) goto LAB_400f236c;
  puVar7 = *(uint **)(&DAT_3f413ee8 + (char)puVar1[0xffef6f7] * 4);
  if ((uint *)0x13ffc < puVar7 + -0xffc0000) goto LAB_400f2328;
LAB_400f2319:
  do {
    puVar6 = in_t0;
    cVar3 = (char)puVar4;
    puVar7 = (uint *)func_0x40094c5c("ude/hal/gpio_ll.h",0x27d,"achPins","t->num)");
    in_t0 = puVar6;
LAB_400f2328:
    memw();
    memw();
    *puVar7 = *puVar7 & 0xffff8fff | 0x2000;
    uVar8 = 0x38;
    if ((char)puVar6[7] != '\0') {
      uVar8 = 0x30;
    }
    param_6 = param_6 + (int)puVar1;
    (*(code *)&SUB_40009edc)(uVar8,*(uint *)(&DAT_3f414510 + param_1 * 0x18) >> 0x14,0);
    *(undefined1 *)(param_6 + 0xc) = 0xff;
LAB_400f236c:
    if (-1 < cVar3) {
      iVar2 = param_1 * 0x20;
      param_6 = iVar2 + 0x3ffbdbd0;
      iVar9 = (int)*(char *)(iVar2 + 0x3ffbdbdd);
      if (iVar9 == cVar3) {
        puVar4 = *(uint **)(&DAT_3f413ee8 + iVar9 * 4);
        puVar1 = puVar4 + -0xffc0000;
        if (puVar1 < (uint *)0x13ffd) goto LAB_400f2319;
        memw();
        memw();
        *puVar4 = *puVar4 & 0xffff8fff | 0x2000;
        (*(code *)&SUB_40009f0c)(iVar9,0x100,0);
        *(undefined1 *)(iVar2 + 0x3ffbdbdd) = 0xff;
      }
    }
    if (-1 < (char)puVar5) {
      iVar2 = param_1 * 0x20;
      puVar4 = (uint *)(iVar2 + 0x3ffbdbd0);
      if ((int)*(char *)(iVar2 + 0x3ffbdbde) == (int)(char)puVar5) {
        puVar5 = *(uint **)(&DAT_3f413ee8 + *(char *)(iVar2 + 0x3ffbdbde) * 4);
        param_6 = 0x13ffc;
        puVar1 = puVar5 + -0xffc0000;
        if (puVar1 < (uint *)0x13ffd) goto LAB_400f2319;
        memw();
        memw();
        *puVar5 = *puVar5 & 0xffff8fff | 0x2000;
        (*(code *)&SUB_40009edc)(0x30,*(uint *)(&DAT_3f414518 + param_1 * 0x18) >> 0x14,0);
        param_6 = 0x2000;
        *(undefined1 *)(iVar2 + 0x3ffbdbde) = 0xff;
      }
    }
    param_5 = (uint)(char)param_5;
    if ((int)param_5 < 0) {
      return 1;
    }
    iVar2 = param_1 * 0x20;
    param_1 = iVar2 + 0x3ffbdbd0;
    uVar10 = (uint)*(char *)(iVar2 + 0x3ffbdbdf);
    if (uVar10 != param_5) {
      return 1;
    }
    puVar4 = *(uint **)(&DAT_3f413ee8 + uVar10 * 4);
    puVar5 = (uint *)0x13ffc;
    puVar1 = puVar4 + -0xffc0000;
    if ((uint *)0x13ffc < puVar1) {
      memw();
      memw();
      *puVar4 = *puVar4 & 0xffff8fff | 0x2000;
      (*(code *)&SUB_40009f0c)(uVar10,0x100,0);
      *(undefined1 *)(iVar2 + 0x3ffbdbdf) = 0xff;
      return 1;
    }
  } while( true );
}

