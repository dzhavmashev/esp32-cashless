// Function : FUN_40100b68
// Address  : 0x40100b68
// Size     : 190 bytes


uint FUN_40100b68(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar5 = *(int *)(param_1 + 0xc);
  uVar2 = 0x102;
  if ((iVar5 != 0) && (uVar2 = 0x5004, *(int *)(iVar5 + 0x34) != 1)) {
    puVar6 = *(undefined4 **)(iVar5 + 8);
    iVar3 = *(int *)(iVar5 + 0x10);
    *puVar6 = 0;
    puVar6[2] = 0;
    puVar6[1] = 0;
    memw();
    FUN_4010aa28(1);
    if (iVar3 == 0) {
      *(undefined4 *)(iVar5 + 0x34) = 0;
      memw();
      uVar2 = 0;
    }
    else {
      uVar2 = *(byte *)(iVar3 + 0xeb) & 1;
      if ((*(byte *)(iVar3 + 0xeb) & 1) == 0) {
        *(uint *)(iVar5 + 0x34) = uVar2;
      }
      else {
        *(undefined4 *)(iVar3 + 4) = 0;
        *(undefined4 *)(iVar3 + 8) = 0;
        *(undefined4 *)(iVar3 + 0xc) = 0;
        *(undefined4 *)(iVar3 + 0x10) = 0;
        *(undefined1 *)(iVar3 + 0x14) = 0;
        *(undefined1 *)(iVar3 + 0x18) = 0;
        *(undefined4 *)(iVar3 + 0x1c) = 0;
        *(undefined4 *)(iVar3 + 0x20) = 0;
        *(undefined4 *)(iVar3 + 0x24) = 0;
        *(undefined4 *)(iVar3 + 0x28) = 0;
        *(undefined1 *)(iVar3 + 0x2c) = 0;
        *(undefined1 *)(iVar3 + 0x30) = 0;
        *(undefined4 *)(iVar3 + 0x34) = 0;
        *(undefined4 *)(iVar3 + 0x38) = 0;
        *(undefined4 *)(iVar3 + 0x3c) = 0;
        *(undefined4 *)(iVar3 + 0x40) = 0;
        *(undefined1 *)(iVar3 + 0x44) = 0;
        *(undefined1 *)(iVar3 + 0x48) = 0;
        memw();
        memw();
        FUN_40100b38(iVar5);
        cVar1 = FUN_401152d8(iVar3);
        if (cVar1 == '\0') {
          (*(code *)&LAB_40185432_2)(iVar3,&DAT_40100cb8);
          *(undefined4 *)(iVar5 + 0x34) = 1;
          memw();
          uVar2 = 0;
        }
        else {
          uVar4 = (*(code *)&SUB_40094b80)();
          FUN_4012113c(1,&PTR_s_STA_DEF_3f40e714,"t (%x)\n",uVar4,&PTR_s_STA_DEF_3f40e714);
          uVar2 = 0x5003;
        }
      }
    }
  }
  memw();
  return uVar2;
}

