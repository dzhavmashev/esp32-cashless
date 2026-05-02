// Function : FUN_400ee814
// Address  : 0x400ee814
// Size     : 260 bytes


int FUN_400ee814(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  int aiStack_24 [9];
  
  iVar1 = (*(code *)&LAB_40184637_1)(param_1);
  if (iVar1 == 0) {
    if (((int *)*param_1 != (int *)0x0) && (param_1[2] == 0)) {
      (**(code **)(*(int *)*param_1 + 8))(aiStack_24);
      iVar2 = param_1[1];
      param_1[1] = aiStack_24[0];
      aiStack_24[0] = iVar1;
      if (iVar2 != 0) {
        FUN_40184618();
      }
      FUN_400ee804(aiStack_24);
      if (param_1[1] == 0) {
        uVar6 = func_0x40085c04();
        uVar3 = FUN_401847ec(&DAT_3f409fe7);
        uVar4 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
        FUN_4012105c("ation: ",uVar4,uVar3,0x478,"\r\n");
        return 0;
      }
      param_1[2] = param_1[1];
    }
    if (param_1[2] != 0) {
      if (param_1[1] != 0) {
        puVar5 = param_1 + 3;
        if ((*(byte *)((int)param_1 + 0x1b) & 0x80) == 0) {
          puVar5 = (undefined4 *)param_1[3];
        }
        iVar2 = (**(code **)(*(int *)*param_1 + 0xc))((int *)*param_1,param_1[2],puVar5);
        if (iVar2 == 0) {
          (**(code **)(*(int *)param_1[2] + 0x3c))();
          return 0;
        }
      }
      puVar5 = param_1 + 3;
      if ((*(byte *)((int)param_1 + 0x1b) & 0x80) == 0) {
        puVar5 = (undefined4 *)param_1[3];
      }
      iVar2 = (**(code **)(*(int *)param_1[2] + 0x4c))
                        ((int *)param_1[2],puVar5,*(undefined2 *)(param_1 + 7),param_1[8]);
      if (iVar2 != 0) {
        (**(code **)(*(int *)param_1[2] + 0x50))
                  ((int *)param_1[2],(*(ushort *)((int)param_1 + 0x26) + 500) / 1000);
        iVar1 = (*(code *)&LAB_40184637_1)(param_1);
      }
    }
  }
  else {
    while (iVar2 = (**(code **)(*(int *)param_1[2] + 0x18))(), 0 < iVar2) {
      (**(code **)(*(int *)param_1[2] + 0x1c))();
    }
  }
  return iVar1;
}

