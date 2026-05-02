// Function : FUN_40165b40
// Address  : 0x40165b40
// Size     : 462 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40165b40(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 *puVar5;
  uint *puVar6;
  uint uVar7;
  uint auStack_40 [2];
  uint *puStack_38;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  
  _DAT_3ffc0704 = (uint *)(**(code **)(_DAT_3ffc1a34 + 0x168))(param_1 * 0xc & 0xffff);
  if (_DAT_3ffc0704 == (uint *)0x0) {
    memw();
    FUN_40147fe4(6,1,1,"l is %d",param_1);
  }
  else {
    if (_DAT_3ffc8af0 != 0) {
      *(undefined4 *)(_DAT_3ffc0034 + 0x3b8) = 0x8a4;
    }
    memw();
    FUN_40147fe4(6,1,3,0x3f435b50,*(undefined4 *)(_DAT_3ffc0034 + 0x3b8));
    uVar3 = 0;
    uStack_30 = param_1 & 0xffff;
    uStack_2c = *(int *)(_DAT_3ffc0034 + 0x3b8) + 4;
    uVar7 = uStack_2c & 0xffff;
    uStack_2c = uStack_2c & 0xfff;
    memw();
    puVar2 = _DAT_3ffc0704;
    puVar6 = auStack_40;
    while (puVar4 = puVar2, (int)uVar3 < (int)uStack_30) {
      uVar1 = (**(code **)(_DAT_3ffc1a34 + 0x15c))(uVar7);
      if (uVar1 == 0) {
        FUN_40147fe4(6,1,2,0x3f43712b);
        goto LAB_40165c6d;
      }
      memw();
      uStack_28 = uVar1;
      (*(code *)&SUB_4008b530)(uVar1,0,uVar7);
      uVar3 = uVar3 + 1;
      memw();
      memw();
      *puVar4 = *puVar4 & 0xfffff000 | uStack_2c;
      memw();
      memw();
      *puVar4 = *puVar4 | 0x80000000;
      memw();
      memw();
      memw();
      *puVar4 = *puVar4 & 0xff000fff | (*puVar4 & 0xfff) << 0xc;
      memw();
      memw();
      *puVar4 = *puVar4 & 0xbfffffff;
      memw();
      puVar4[1] = uStack_28;
      memw();
      *puVar4 = *puVar4 & 0xdfffffff;
      puVar6[2] = (uint)puVar4;
      puVar2 = puVar4 + 3;
      puVar6 = puVar4;
    }
    puVar6[2] = 0;
    _DAT_3ffc06fc = puStack_38;
    _DAT_3ffc0700 = puVar6;
LAB_40165c6d:
    memw();
    FUN_40147fe4(6,1,3,0x3f435b32,uVar3);
    FUN_40147fe4(6,1,3,0x3f435b13,_DAT_3ffc8adc);
    puVar2 = _DAT_3ffc06fc;
    if (param_1 <= uVar3) {
      for (; puVar2 != (uint *)0x0; puVar2 = (uint *)puVar2[2]) {
        memw();
        memw();
        memw();
        *puVar2 = *puVar2 & 0xfffff000 | (*puVar2 & 0xfff) - 4 & 0xfff;
        memw();
        memw();
        puVar5 = (undefined4 *)puVar2[1];
        memw();
        *puVar2 = *puVar2 & 0xff000fff | (*puVar2 & 0xfff) << 0xc;
        *puVar5 = 0xdeadbeef;
        memw();
        *(undefined4 *)((int)puVar5 + (*puVar2 & 0xfff)) = 0xdeadbeef;
      }
      DAT_3ffc072c = 0;
      memw();
      memw();
      return 0;
    }
    FUN_40147fe4(6,1,1," %s %u\n",param_1,uVar3);
    FUN_40165abc();
  }
  return 0x101;
}

