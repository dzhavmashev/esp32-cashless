// Function : FUN_40172470
// Address  : 0x40172470
// Size     : 123 bytes


int FUN_40172470(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  
  uVar1 = (**(code **)(*param_1 + 0x54))(param_1);
  iVar2 = FUN_40109a64(uVar1,param_2,param_3,param_4,param_5);
  if (iVar2 < 0) {
    uVar8 = (*(code *)&SUB_40085bfc)();
    uVar1 = FUN_401847f4(&DAT_3f424da0);
    uVar3 = (**(code **)(*param_1 + 0x54))(param_1);
    puVar4 = (undefined4 *)FUN_40173a8c();
    uVar7 = *puVar4;
    puVar4 = (undefined4 *)FUN_40173a8c();
    uVar5 = FUN_401745d0(*puVar4);
    uVar6 = (*(code *)&SUB_4000cff8)((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),1000,0);
    FUN_4012105c("uffer\r\n",uVar6,uVar1,0x140,&DAT_3f424f97,uVar3,uVar7,uVar5);
  }
  return iVar2;
}

