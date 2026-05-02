// Function : FUN_400d3a50
// Address  : 0x400d3a50
// Size     : 749 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d3a50(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *****pppppuVar4;
  undefined4 *****pppppuVar5;
  int aiStack_78 [2];
  uint uStack_70;
  uint uStack_6c;
  undefined1 auStack_68 [16];
  undefined4 ****local_58 [3];
  byte bStack_49;
  undefined4 uStack_48;
  undefined1 uStack_44;
  undefined4 ****local_40 [3];
  byte bStack_31;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400d9b60(aiStack_78,0x3ffc4090);
  if ((uStack_6c & 0x80000000) == 0) {
    if (aiStack_78[0] != 0) goto LAB_400d3a83;
  }
  else {
    uStack_70 = uStack_6c >> 0x18 & 0x7f;
LAB_400d3a83:
    if (uStack_70 != 0) {
      FUN_400f0d18(0x3ffc3ff0,aiStack_78);
      FUN_400f0be8(local_58,"figured");
      uVar1 = FUN_400f10c0(local_58,aiStack_78);
      FUN_400f0768(0x3ffc5490,uVar1);
      FUN_400f0a50(local_58);
      FUN_400d36e0(param_1,1);
      FUN_400f0be8(local_58,"r URL: ");
      FUN_400d3874(param_1,local_58);
      FUN_400f0a50(local_58);
      iVar2 = FUN_400d3694(param_1);
      if (iVar2 != 0) {
        FUN_400d36e0(param_1,2);
        FUN_400f0be8(local_58,"ication");
        FUN_400d3874(param_1,local_58);
        FUN_400f0a50(local_58);
        FUN_400f0be8(local_58,&DAT_3f42161d);
        uStack_48 = 0x22b3;
        uStack_44 = 1;
        FUN_400f0be8(local_40,&DAT_3f42161d);
        uStack_30 = 0x3c;
        uStack_2c = 300;
        uStack_28 = 1;
        iVar2 = FUN_400d6844(0x3ffc3ff0,local_58);
        if (iVar2 == 200) {
          FUN_400f0780(0x3ffc5490," server");
          FUN_400f0780(0x3ffc5490,"cessful");
          pppppuVar4 = local_58;
          if ((bStack_49 & 0x80) == 0) {
            pppppuVar4 = (undefined4 *****)local_58[0];
          }
          pppppuVar5 = local_40;
          if ((bStack_31 & 0x80) == 0) {
            pppppuVar5 = (undefined4 *****)local_40[0];
          }
          FUN_400f06a4(0x3ffc5490,"Config:",pppppuVar4,uStack_48,pppppuVar5);
          FUN_400d36e0(param_1,3);
          FUN_400f0be8(auStack_68,"ID: %s\n");
          FUN_400d3874(param_1,auStack_68);
          FUN_400f0a50(auStack_68);
          iVar2 = FUN_400d38e8(param_1,local_58);
          if (iVar2 != 0) {
            FUN_400f0780(0x3ffc5490,"aborted");
            FUN_400d9a2c(0x3ffc4090,local_58);
            FUN_400d98d0(0x3ffc4090,1);
            if (*(int *)(param_1 + 0x28) != 0) {
              (**(code **)(param_1 + 0x2c))(param_1 + 0x20,local_58);
            }
            goto LAB_400d3ca4;
          }
          FUN_400f0780(0x3ffc5490,"ctivity");
          iVar2 = *(int *)(param_1 + 0x38);
        }
        else {
          iVar3 = param_1 + 4;
          FUN_400f0d4c(auStack_68,0x3ffc4000);
          FUN_400f0d60(iVar3,auStack_68);
          FUN_400f0a50(auStack_68);
          *(int *)(param_1 + 0x14) = iVar2;
          if ((*(byte *)(param_1 + 0x13) & 0x80) == 0) {
            iVar3 = *(int *)(param_1 + 4);
          }
          FUN_400f06a4(0x3ffc5490,"uration",iVar2,iVar3);
          iVar2 = *(int *)(param_1 + 0x38);
        }
        if (iVar2 != 0) {
          FUN_400d3a30(param_1 + 0x30,*(undefined4 *)(param_1 + 0x14),param_1 + 4);
        }
        iVar2 = 0;
LAB_400d3ca4:
        FUN_400f0a50(local_40);
        FUN_400f0a50(local_58);
        param_1 = iVar2;
        goto LAB_400d3acc;
      }
      iVar2 = param_1 + 4;
      FUN_400f0d70(iVar2,"or mTLS");
      uVar1 = 0xffffffff;
      *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
      if (*(int *)(param_1 + 0x38) != 0) goto LAB_400d3af1;
      goto LAB_400d3aca;
    }
  }
  iVar2 = param_1 + 4;
  FUN_400f0d70(iVar2,"n state");
  *(undefined4 *)(param_1 + 0x14) = 0xfffffffe;
  FUN_400f0be8(local_58,"omplete");
  uVar1 = FUN_400f10c0(local_58,iVar2);
  FUN_400f0768(0x3ffc5490,uVar1);
  FUN_400f0a50(local_58);
  if (*(int *)(param_1 + 0x38) != 0) goto LAB_400d3aed;
LAB_400d3aca:
  while( true ) {
    param_1 = 0;
LAB_400d3acc:
    FUN_400f0a50(aiStack_78);
    iVar2 = iStack_24;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
LAB_400d3aed:
    uVar1 = *(undefined4 *)(param_1 + 0x14);
LAB_400d3af1:
    FUN_400d3a30(param_1 + 0x30,uVar1,iVar2);
  }
  return;
}

